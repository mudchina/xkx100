//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{
	set ("short", "花圃");
	set ("long", @LONG
这是知府衙门里的花圃。花圃中有几盆颜色特别娇艳的黄花。这些
花的花瓣黄得象金子一样，闪闪发亮，花朵的样子很象荷花，只是没荷
花那么大。北边是知府大人的书房，南边是客厅。东边是知府大人和家
眷的住处。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([ 
		"north" : __DIR__"shufang",
		"south" : __DIR__"keting",
		"east"  : __DIR__"dongxiang",
		"west"  : __DIR__"datang",
	]));
	set("objects", ([
		__DIR__"obj/jinboxunhua" : 2,
	]));

	set("coor/x", -1488);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
