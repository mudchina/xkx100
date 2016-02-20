// Room: /d/nanshaolin/jnlwang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "紧那罗王殿");
	set("long", @LONG
大殿正中供奉着紧那罗王的三座塑像。四周的墙壁上绘满了西方胜
境，四十八愿，二十四尊天的壁画，构图宏伟，色彩绚丽，线条流畅，
画工精细。殿中有几名香客正在顶礼膜拜。
LONG );

	set("exits", ([
		"west" : __DIR__"pingtai",
	]));
	set("objects",([
		WEAPON_DIR+"hammer/muchui" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6210);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}



