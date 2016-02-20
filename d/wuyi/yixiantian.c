// Room: /d/wuyi/yunwo.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "一线天");
	set("long", @LONG
一线天原名灵岩，位于二曲之南。因岩壁纵裂一线，天光如丝，而
得今名。南壁峭崖下，三洞森然。入洞后，顿觉阴气森森，暑气全消。
仰窥丹崖，如鬼斧神工，数十丈一线青天，弯曲如虹。相传此处为伏羲
上古因悲天悯人，手抡玉斧劈开的。岩壁上数以千计的白蝙蝠，也是人
间罕见的奇观。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"path6",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -5050);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

