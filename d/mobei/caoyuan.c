// Room: /d/mobei/caoyuan.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "蒙古草原");
	set("long", @LONG
这如海般的蒙古草原，浩淼无边，天空中苍鹰掠过，发出尖尖的哨
音。身边的牛羊缓缓的移动。西边是个小土丘，上面长满了灌木丛。
LONG);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huazheng" : 1,
	]));
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 3 */
		"westup" : __DIR__"guanmu1",
		"south" : __DIR__"caoyuan2",
		"north" : __DIR__"caoyuan4",
	]));
	set("coor/x", -230);
	set("coor/y", 5170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
