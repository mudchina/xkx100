// Room: /d/wuyi/4qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "四曲");
	set("long", @LONG
这里有深不可测的卧龙潭。相传原先这里蛰伏了十条恶龙，为非作
歹，伤害无辜。许仙手执七星宝剑杀其九。小龙痛改前非，许仙于是就
放它一条生路，从此造福百姓。朱熹《九曲棹歌》曰：“……四曲东西
两石岩，岩花垂露碧阑毵，金鸡叫罢无人见，月满空山水满潭。……”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"shijianshi",
		"southup"   : __DIR__"dazangfeng",
		"northeast" : __DIR__"3qu",
		"southwest" : __DIR__"5qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

