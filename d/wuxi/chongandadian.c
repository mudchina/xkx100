// Room: /d/wuxi/chongandadian.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "崇安寺大殿");
	set("long", @LONG
殿内正中供着塑金佛象，僧人诵经之声不绝于耳。进出的香客显
得十分地虔诚，四周一圈是五轮大藏佛像。高高的殿堂里，帏幔飘垂
香火缭绕，显得特别地神秘。无锡人都说，在这里许愿十分地灵验。
LONG );
	set("no_beg", 1);
	set("exits", ([
		"out"  : __DIR__"chongansi",
	]));
	set("objects", ([
		__DIR__"npc/laoheshang": 1,
	]));
	set("coor/x", 381);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}