// Room: /heizhao/hzneitang.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "黑沼内堂");
	set("long", @LONG
内堂中间安了一张长桌，上面放着七盏油灯，排成天罡北斗之
形。左首有一张椅上，地下蹲着一个头发花白的女子，身披麻衫，
凝目瞧着地下一根根长约四寸，阔约二分，计数用的算子，显然正
自潜心思索，虽听得有人进来，却不抬头。
LONG );
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"hzyuanzi",
		"north" : __DIR__"hzneishi",
	]));
	set("objects", ([
		__DIR__"npc/yinggu" : 1,
	]));
	set("coor/x", -5100);
	set("coor/y", -1480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}