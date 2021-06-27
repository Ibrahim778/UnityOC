# UnityOC
Overclock your vita right from Unity!

# Requirements
Taihen (should already be installed)
(VitaFTPI-Core)[https://github.com/Ibrahim778/VitaFTPI-Core]

If you don't want to install VitaFTPI (which I highly recommend you do) See the manual install section.

# Install

1. Download file UniyOC.zip and extract (anywhere). 
2. Make a folder called "Plugins" (without "") inside your Assets folder. 
3. Copy UnityOC.suprx and UnityOC_stub.a to the Plugins folder (make sure only PSP2 platform is selected!). 
4. Make a folder called CustomPlugins (without "") inside your Assets folder. 
5. Download a release of my version of oclockvita.suprx from (here)[https://github.com/Ibrahim778/oclockvita/releases]
6. Copy that to the CustomPlugins folder (In settings make sure **no** platform is selected!)
7. Copy the provided script UnityOC.cs to your project. (make sure to add it to a GameObject!)
8. Done!!

# Usage
You can call the static UnityOC methods from anywhere. For example

```
void Start()
{
    UnityOC.SetFrequencies(444,222,222,166);
}
```

This will Overclock your vita to 444/222/222/166 (which is the highest you can do from usermode, see Limitations).

To reset, you can call UnityOC.ResetFrequencies in the same way.

# Limitations
Right now this is all done from usermode, so you cannot:
Overclock > 444/222/222/166
Underclock < 333/111/111/111

# Manual Install
Since oclockvita is a vitaSDK plugin Unity will not build if you include it in your projects. Thus you need to manually copy it to the build everytime, VitaFTPI does this for you, but here's how you can do it yourself (if for some reason you don't want VitaFTPI, I highly recommend you check it out):

1. Build like normal
2. Copy oclockvita.suprx to the Media/Plugins folder in the build
3. Run UnityTools like normal
4. Install normally

# Credits
@iDevOnAParkingLot for giving me the idea
@frangarcj for oclockvita
