// Room: /yangzhou/shanmen.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","山门");
	set("long",@LONG
山门上嵌“大明寺”石额，集唐代扬州书法家李邕手迹。山门东西
折墙嵌石刻各一，东为“淮东第一观”，录秦观《次子由平山堂韵》句，
清著名书法家蒋衡书；西为清吏部员外郎王澍书“天下第五泉”。
    康熙时忌讳“大明”二字，沿称栖灵寺，乾隆巡幸扬州，亲笔改题
“法净寺”，俗称“平山堂”。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"north"     : __DIR__"tianwangdian",
		"southdown" : __DIR__"pailou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 140);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}