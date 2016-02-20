// Room: /d/heimuya/dating4.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "天香堂");
	set("long", @LONG
这是『日月神教』下第四大堂：天香堂的大厅，远远望去郁郁渺渺，
好似不食人间烟火。堂梁上有一块匾(bian)。
LONG    );
	set("exits", ([
		"west"    : __DIR__"road1",
		"southup" : __DIR__"tian1",
	]));
	set("item_desc", ([
		"bian": "上面写到：天香堂---日月神教圣姑住地。\n",
       	]) );
	set("no_clean_up", 0);
	set("coor/x", -3010);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}