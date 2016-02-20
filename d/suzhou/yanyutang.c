// Room: /d/suzhou/yanyutang.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "燕誉堂");
	set("long", @LONG
燕誉堂是全园主厅，旧时系园主宴客处。曾经作为御膳房。堂名取
于《诗经》：“式燕且誉，好而无射”。此处建筑为鸳鸯厅形状，高敞
宏丽，堂内陈设富丽精致。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"shizilin",
		"southeast" : __DIR__"zhenquting",
	]));
	set("objects", ([
		__DIR__"npc/lady3" : 2,
	]));
	set("coor/x", 870);
	set("coor/y", -1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
