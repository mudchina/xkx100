// Room: /yangzhou/caotang.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "湖上草堂");
	set("long", @LONG
湖上草堂面西三楹。内悬嘉庆扬州知府伊秉绶书题额“湖上草堂”
及集句楹联(lian)。堂外平台围以石栏，柱头雕有石狮，栏板为古松纹
饰，平台中植有一对百年紫薇，夏日红花累累。栏外置画舫码头。草堂
之北、玉佛洞前有唐代银杏枯木两片，一大一小，形似千年枯树，上攀
古藤凌霄，枯木系木。银杏木质坚韧，至今尚未腐朽，敲击有声。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIW"
        白        幽
        云        赏
        初        未
        晴        已

        旧        高
        雨        潭
        适        转
        至        清
\n"NOR
	]));
	set("exits", ([
		"west"    : __DIR__"lunlian",
		"northup" : __DIR__"guanyindian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 110);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}