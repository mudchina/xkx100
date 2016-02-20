// Room: /d/wuxi/shuchang.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "吟春书场");
	set("long", @LONG
这虽然是一家南方的书场，但也懂得兼容并绪。常有来自北方的
京韵大鼓艺人、中原的评书艺人上座献艺，当然，最多最受欢迎的还
是附近的苏州评弹。跑堂的在听书的客人中间跑来穿去，传递着茶水
和毛巾，服务甚是殷勤。
LONG );
	set("exits", ([
		"east" : __DIR__"southroad2",
	]));
	set("objects", ([
		__DIR__"npc/shuke" : 1,
	]));
	set("coor/x", 360);
	set("coor/y", -830);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}