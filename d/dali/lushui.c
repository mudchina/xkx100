//Room: /d/dali/lushui.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","泸水沿岸");
	set("long",@LONG
一条土路沿着泸水纵贯谷地南北，脚下泸水滔滔流去，长年累月
冲刷着谷中大地，东面碧罗雪山、西面的高黎山皆高耸蔽日。土路北
通此谷中心大镇巴的甸，南连数个乌夷小部落。
LONG);
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"badidian",
	    "south"      : __DIR__"atoubu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -90000);
	set("coor/y", -70010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}