//Room: /d/dali/dating.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","五华楼大厅");
	set("long",@LONG
这里是五华楼的前大厅，异常宽敞明亮，足有一里见方，全是云
石铺地，黑白相间，足足可以容纳二、三千人。时时可见锦衣侍者手
托美食来回行走。
LONG);
	set("objects", ([
	   __DIR__"npc/shizhe": 3,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"   : __DIR__"louti",
	    "out"     : __DIR__"gudao",
	]));
	set("coor/x", -50000);
	set("coor/y", -75010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}