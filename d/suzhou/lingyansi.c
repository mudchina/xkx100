// Room: /d/suzhou/lingyansi.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "灵岩寺");
	set("long",@long
爬上山顶，就是灵岩寺。灵岩寺原系吴王馆娃宫遗址，为“东南著
名丛林”，佛教净土宗道场。始建于南朝，原名绣峰寺。唐代改称灵岩
寺，信奉律宗。
long);
	set("objects",([
		__DIR__"npc/ke" : 2,
	]));
	set("exits",([
		"northdown" : __DIR__"shiyuan",
		"west"      : __DIR__"zhonglou",
		"east"      : __DIR__"lingyanta",
		"enter"     : __DIR__"dxbdian",
	]));
	set("outdoors","suzhou");
	set("coor/x", 900);
	set("coor/y", -1120);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
