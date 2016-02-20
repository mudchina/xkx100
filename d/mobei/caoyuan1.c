// Room: /d/mobei/caoyuan1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "蒙古草原");
	set("long", @LONG
远处烟尘起处，一队队蒙古铁骑列队来往操练。西边夕阳如血，混
圆的残阳下是连绵的营帐和牛羊，那就是铁木真的部落。东面的树林边
几个小孩正在玩耍，树林后面是座荒山。 
LONG);
	set("outdoors","mobei");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/tujiu" : 2,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"shulin",
		"south" : __DIR__"shulin5",
	]));
	set("coor/x", -230);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
