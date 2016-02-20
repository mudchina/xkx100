// Room: /d/qilian/danshan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "丹山");
	set("long", @LONG
此地又名装山，自古以产铜著称，在嘉峪关西一百八十里，峰峦高
耸，下有小红石，可以炼铜，相传是女蜗补天时撒下。南望山下一条商
路穿过嘉峪关贯通东西。
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"yumenguan",
		"southeast" : "/d/xingxiu/jiayuguan",
	]));
	set("coor/x", -20000);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}