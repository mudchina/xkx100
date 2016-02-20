// /d/taohuacun/road3.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set("short","田间小路");
	set("long", @LONG
这里是小路的尽头，北方不远处有间农舍，隐约可见袅袅的炊烟升
起。南面望去，一条小路从一畦畦菜田中蜿蜒而远去。
LONG
);
	set("exits", ([
		"south" : __DIR__"road2",
		"north" : __DIR__"kitchen",
		"west"  : __DIR__"taohua6",
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}