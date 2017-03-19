set ACE_ROOT=%CD%
perl %ACE_ROOT%\bin\mwc.pl -type vc10 -static -features ssl=1 -features uses_wchar=1 -features acexml=0 -features ace_svcconf=0 -features ace_token=0 -features ace_idl_dependencies=0 -expand_vars ace protocols
