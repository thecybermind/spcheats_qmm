mkdir package
pushd package
del /q *
copy ..\README.md .\
copy ..\LICENSE .\

for %%x in (Q2R Q3A QUAKE2) do (
    copy ..\bin\Release-%%x\x86\spcheats_qmm_%%x.dll .\
    copy ..\bin\Release-%%x\x64\spcheats_qmm_x86_64_%%x.dll .\     
)
popd
