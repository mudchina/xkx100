// Room: /d/mobei/chahe.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "察合台营帐");
	set("long", @LONG
察合台是铁木真的二子，生性残忍好杀，蒙古人性喜打猎，酋长贵
人无不畜养猎犬猎鹰。察合台尤其爱狗，不但在营帐外面拴了獒犬，营
帐中还有獒犬的笼子。
LONG);
	set("outdoors","mobei");
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/menggudog" : 1,
		__DIR__"npc/chahetai" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"road2",
	]));
	set("coor/x", -200);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
