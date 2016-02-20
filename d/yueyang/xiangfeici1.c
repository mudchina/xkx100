// Room: /d/yueyang/xiangfeici1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "湘妃祠");
	set("long", @LONG
湘妃祠座落在二妃墓的东北侧，它东临洞庭湖，远映岳阳甑箪山，
后以苍松翠柏为屏，小青瓦盖面，素而古朴。白的院墙，青色的屋面，
与青山遥相呼应，白墙与蓝天绿树，相映和谐。大门上方由两条龙捧着
“湘妃祠”的三个金色大字，门内便是湖广总督张之洞撰写的四百字的
天下第一联。南面的红墙上，为九嶷山图，北面是烟波水浮的君山。诗
人孙宜题此：“凄凄湘君调，惋惋舜帝吟。载歌屈原咏，落日愁沾襟。”
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"out"   : __DIR__"xiaolu6",
		"north" : __DIR__"xiangfeici2",
	]));
	set("coor/x", -1660);
	set("coor/y", 2310);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
