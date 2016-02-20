// Room: /d/tiezhang/hxfang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "后厢房");
	set("long", @LONG
这是大厅后面的一个小房间，虽然也是岩石砌成，但布置的非常舒
适。四壁用挂毯遮住，不露一点石壁的痕迹。屋内转圈摆放了一些椅子，
上面铺着厚厚的软垫，坐上去一定很舒适。这里是帮主处理帮中日常事
务的地方。后面通向后花院。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"hhyuan1",
		"south" : __DIR__"wztang",
        ]));
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}