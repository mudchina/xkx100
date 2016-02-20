//ROOM: /d/yanziwu/zhulin3.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long",@LONG
凤尾森森，龙吟细细，竿竿青竹纵横交错，遮蔽天日。这里人迹罕
至，微风拂过竹林，发出沙沙之声，你心中不免惴惴不安起来。林中一
道道石子铺成的羊肠小道向前延伸。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"west" : __DIR__"zhulin4",
		"east" : __DIR__"zhulin3",
		"north": __DIR__"qingzong",
		"south": __DIR__"zhulin2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1490);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}