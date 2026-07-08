# $Id: testload.tcl,v 1.4 2025/08/01 05:29:38 cvswxc Exp $ 
set testlog [format "/tmp/testlog%d" [pid]]
set serverlog [format "%s%s" $testlog "-server"]
set clientlog [format "%s%s" $testlog "-client"]
set thishost $env(thishost)

set defaultport "2718"

#if ILUTESTWIN not set, assume unix platform
if [ catch  {set x $env(ILUTESTWIN)} dummy ] {
    set killsignal "-9"
} else {
  set killsignal "/f"
}

source xform-testurls.tcl

if { [ transform-urls ] == 0} {
  exit 1
}

set iserror 0

source testprocs.tcl 
