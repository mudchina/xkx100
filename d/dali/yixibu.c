//Room: /d/dali/yixibu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","易溪部");
	set("long",@LONG
易溪部也是乌夷族乌杂蛮的部落。这里处半坡地，附近有不少农
田，但农业落后，需要换季轮耕，因而村民经常迁徙，镇子里除了祭
祀大屋外，其它房屋都很简陋。
LONG);
	set("objects", ([
	   __DIR__"npc/shaonu": 1,
	]));
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : __DIR__"atoubu",
	    "south"      : __DIR__"wuyiminju4",
	    "east"       : __DIR__"biluoshan",
	]));
	set("coor/x", -89990);
	set("coor/y", -70030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}