//Room: /d/dali/tingfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","花厅");
	set("long",@LONG
这里是镇南王府的内厅。整个大厅十分宽阔。虽说是王府，但摆
设很简单，正中间有两张太师椅，边上摆满了各种各样的山茶花。
LONG);
	set("objects",([
	    CLASS_D("dali")+"/guducheng": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"yongdao1",
	    "west"   : __DIR__"chufang",
	    "east"   : __DIR__"shufang",
	    "south"  : __DIR__"changlang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38980);
	set("coor/y", -69990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}