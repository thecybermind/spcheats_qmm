for %%x in (Q2R Q3A QUAKE2) do (
    msbuild .\msvc\spcheats_qmm.vcxproj /p:Configuration=Debug-%%x /p:Platform=x86
    msbuild .\msvc\spcheats_qmm.vcxproj /p:Configuration=Debug-%%x /p:Platform=x64
)
