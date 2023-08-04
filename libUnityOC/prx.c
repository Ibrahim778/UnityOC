#include <kernel.h>
#include <taihen.h>
#include <power.h>

#define EXPORT __declspec (dllexport)

#define HOOK_NUM 4

SceUID hooks[HOOK_NUM];
tai_hook_ref_t hook_refs[HOOK_NUM];

int arm = -1, bus = -1, gpu = -1, xbar = -1;

EXPORT int SetFrequencies(int _arm, int _bus, int _gpu, int _xbar)
{
	arm = _arm;
	bus = _bus;
	gpu = _gpu;
	xbar = _xbar;

	scePowerSetArmClockFrequency(_arm);
	scePowerSetBusClockFrequency(_bus);
	scePowerSetGpuClockFrequency(_gpu);
	scePowerSetGpuXbarClockFrequency(_xbar);

	return 0;
}

int scePowerSetArmClockFrequency_Patch(int freq)
{
	if (arm == -1)
		return TAI_CONTINUE(int, hook_refs[0], freq);

	return TAI_CONTINUE(int, hook_refs[0], arm);
}

int scePowerSetBusClockFrequency_Patch(int freq)
{
	if (bus == -1)
		return TAI_CONTINUE(int, hook_refs[1], freq);

	return TAI_CONTINUE(int, hook_refs[1], bus);
}

int scePowerSetGpuClockFrequency_Patch(int freq)
{
	if (gpu == -1)
		return TAI_CONTINUE(int, hook_refs[2], freq);

	return TAI_CONTINUE(int, hook_refs[2], gpu);
}

int scePowerSetGpuXbarClockFrequency_Patch(int freq)
{
	if (xbar == -1)
		return TAI_CONTINUE(int, hook_refs[3], freq);

	return TAI_CONTINUE(int, hook_refs[3], xbar);
}

int module_start(SceSize args, void *argp)
{
	hooks[0] = taiHookFunctionImport(&hook_refs[0],
		TAI_MAIN_MODULE,
		TAI_ANY_LIBRARY,
		0x74DB5AE5, // scePowerSetArmClockFrequency
		scePowerSetArmClockFrequency_Patch);

	hooks[1] = taiHookFunctionImport(&hook_refs[1],
		TAI_MAIN_MODULE,
		TAI_ANY_LIBRARY,
		0xB8D7B3FB, // scePowerSetBusClockFrequency
		scePowerSetBusClockFrequency_Patch);

	hooks[2] = taiHookFunctionImport(&hook_refs[2],
		TAI_MAIN_MODULE,
		TAI_ANY_LIBRARY,
		0x717DB06C, // scePowerSetGpuClockFrequency
		scePowerSetGpuClockFrequency_Patch);

	hooks[3] = taiHookFunctionImport(&hook_refs[3],
		TAI_MAIN_MODULE,
		TAI_ANY_LIBRARY,
		0xA7739DBE, // scePowerSetGpuXbarClockFrequency
		scePowerSetGpuXbarClockFrequency_Patch);

	return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize args, void *argp)
{
	for (int i = 0; i < HOOK_NUM; i++)
		taiHookRelease(hooks[i], hook_refs[i]);

	return SCE_KERNEL_STOP_SUCCESS;
}