# UnityOC
Overclock your vita right from Unity!

## Usage
### Quick Install
Simply download and use the provided `.unitypackage` file in the realese.  
You can add the `VitaClockSetter` script to any game object (it should be just 1) and set your preferred clocks via the editor, which will be applied at runtime.

### Manual Install
1. Create a folder called `Plugins` (case sensitive!) in your Assets folder
2. Copy the 2 release files `libUnityOC.suprx` and `libUnityOC_stub.a` and under platform options make sure `PSP2` is selected
3. Use the script `UnityOC.cs`, present in the root of this git repository, Simply add it to your unity project and you are done.

You can overclock like so:  
```cs
        UnityOC.SetFrequencies(444, 222, 222, 166);
```
And you can reset the clock speeds like so:  
```cs
        UnityOC.ResetFrequencies();
```

## Limitations
Since this all done via usermode you cannot:  
Overclock > 444/222/222/166  
Underclock < 333/111/111/111
