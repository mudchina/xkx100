//Room: /d/dali/ershuiqiao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","洱水桥");
	set("long",@LONG
一座长百余步的青石桥。此桥横跨洱水，连接下关城和大理城，
桥下清澈的洱水滚滚东去。桥北正是下关城的城门，桥南一路南行十
数里即可到大理城。
LONG);
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"xiaguan",
	    "southeast"  : __DIR__"dalinorth",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41000);
	set("coor/y", -58000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}