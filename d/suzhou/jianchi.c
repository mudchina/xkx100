// Room: /d/suzhou/jianchi.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","剑池");
	set("long",@LONG
剑池位于千人石的西南，池形狭长，如一柄平放之剑。池水终年不
干枯。阖闾墓，均无所得，所凿之处遂成深涧，呈剑形。门旁石壁上刻
“虎丘剑池”四个大字。剑池景致幽深独绝，池之两旁，崖壁如削，藤
萝垂挂，左壁刻大篆“剑池”两字。
LONG);
	set("outdoors", "suzhou");
	set("exits",([
		"northeast" : __DIR__"qianrenshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 790);
	set("coor/y", -1030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
