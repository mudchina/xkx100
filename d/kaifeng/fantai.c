// /kaifeng/fanta1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "繁塔");
	set("long", @LONG
繁塔建于繁台之上，这是一座六角九层，八十余米高的巨型佛塔，
极为壮观。有诗曰『台高地迥出半天，了望皇都十里春』，塔高十余丈，
青砖砌成砖雕有精美的佛像，共有一百零八种，七千余尊。塔内存有一
百七十八块佛经碑刻。
LONG
	);
	set("outdoors", "kaifeng");
	set("exits", ([
		"east" : __DIR__"zhulin0",
		"west" : __DIR__"jiedao2",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
