// /kaifeng/sanqing.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "三清殿");
	set("long", @LONG
三清殿供奉的是三清神像，不过开封府内的居民大多到大相国寺去
烧香还愿了，这里的香火并不旺。神像也蓬头垢面无人理会。西行去有
座高高的阁楼，就是玉皇阁。
LONG
	);
	set("objects", ([
		__DIR__"npc/obj/sanqingxiang" : 1,
		__DIR__"npc/xianghuo" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"yanqing",
		"north" : __DIR__"yuhuang1",
	]));

	setup();
	replace_program(ROOM);
}
