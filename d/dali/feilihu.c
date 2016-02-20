//Room: /d/dali/feilihu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","妃丽湖畔");
	set("long",@LONG
你站在妃丽湖的北岸，北边不远就是喜州城。此湖不大，但湖水
清澈，鱼鳖皆有，不少台夷村民划着竹筏在湖上捕鱼。湖之南和东边
半山上都有台夷村镇，有道路绕湖东而过通向南边。
LONG);
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"xizhou",
	    "east"       : __DIR__"luwang",
	    "southeast"  : __DIR__"feilihueast",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40000);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}