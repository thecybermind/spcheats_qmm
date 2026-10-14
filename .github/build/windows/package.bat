mkdir package
pushd package
del /q *
rem copy ..\README.md .\
rem copy ..\LICENSE .\

for %%G in (Q2R Q3A QUAKE2) do (
    copy ..\bin\Release-%%G\x86\spcheats_qmm_%%G.dll .\
    copy ..\bin\Release-%%G\x64\spcheats_qmm_x86_64_%%G.dll .\     
)
popd
