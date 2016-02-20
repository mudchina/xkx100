// /d/shenlong/npcloc/xuloc.c
// Last Modified by winder on Jul. 12 2002

// inherit SKILL;
inherit F_CLEAN_UP;

string *xulocs = ({
	"/d/changbai/tuyaoguan",
	"/d/city/chaguan",
	"/d/lanzhou/southgate",
	"/d/shaolin/shanmen",
	"/d/shenlong/dating",
});

void create() { seteuid(getuid()); }

string query_loc()
{
	return xulocs[random(sizeof(xulocs))];
}
