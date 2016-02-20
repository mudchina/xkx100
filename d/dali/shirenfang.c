//Room: /d/dali/shirenfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","石人房");
	set("long",@LONG
这里是镇南王府的庭院南端的石人房，房中摆着一些大理特产的
石人，看起来栩栩如生。四壁开着小窗口，窗台上放着几钵小茶花，
窗口栏杆也挡不住窗外四时不尽的绿色和芳香。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "north" : __DIR__"tingyuan",
	]));
	set("objects",([ /* sizeof() == 1 */
	    __DIR__"npc/shi-ren" : 5,
	]));
	set("coor/x", -38980);
	set("coor/y", -70010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}