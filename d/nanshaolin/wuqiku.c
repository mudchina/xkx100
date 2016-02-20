// Room: /d/nanshaolin/wuqiku.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
少林寺的武器库可称天下第一，十八般兵器，这里可谓应有尽有。
四面一望，令你顿感眼花缭乱。墙上砌了一个个小格子，每个都插满了
各种各样的兵器。墙角一个健壮的僧人正乒乒乓乓地在打造一根禅杖。
另一位灰衣僧人正在墙角拂拭一把戒刀。看到你进来，他缓缓起身，向
你迎了过来。
LONG );
	set("exits", ([
		"south" : __DIR__"lshuyuan",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangchen" : 1,
		WEAPON_DIR+"sword/zhujian" : 1,
		WEAPON_DIR+"blade/mudao" : 1,
	]));
	set("coor/x", 1790);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

