// Room: /yangzhou/lunlian.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "绿筱沦涟");
	set("long", @LONG
绿筱沦涟在湖上草堂之西，面西三楹，三面廊两山各开方窗。馆内
悬陈重庆题书“绿筱沦涟”匾，跋曰：“此处旧名绿荫馆，二分竹，三
分水，至佳境也。取康乐诗句，改题此额。”馆门外悬“绿荫馆”匾。
外柱悬有一楹联(lian)。
    馆前平台围以石栏，台中植一对黑松，虬曲苍劲。松间置一方石壶，
上刻“小蓬壶”，并有篆文：“借山叠石因成趣，种竹依花为有香”。
由绿柳堤西行迳达吹台。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIG"
        四        三
        面        更
        绿        画
        荫        船
        少        穿
        红        藕
        日        花
\n"NOR
	]));
	set("exits", ([
		"east"  : __DIR__"caotang",
		"south" : __DIR__"pingtai2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}