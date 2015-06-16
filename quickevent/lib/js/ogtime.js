.pragma library

function msecToString(msec, sec_sep, msec_sep)
{
	if(!sec_sep)
		sec_sep = "."
	var ms = msec % 1000;
	var sec = ((msec / 1000) >> 0) % 60;
	var min = (msec / (1000 * 60)) >> 0;
	var ret = min + sec_sep;
	if(sec < 10)
		ret += '0';
	ret += sec;
	if(msec_sep) {
		ret += msec_sep;
		if(ms < 100)
			ret += '0';
		if(ms < 10)
			ret += '0';
		ret += ms;
	}
	return ret;
}

