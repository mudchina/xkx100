// yunu.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "玉女峰");
	set("long", @LONG
这里是华山的中峰，玉女峰。传说春秋时隐士萧史善吹洞箫，箫声
引动了秦穆公女儿弄玉的爱慕，抛弃了宫廷生活，跟萧史来此隐居，故
称玉女峰。这里地势略为平缓，不似其它四峰般险峻，江湖上赫赫有名
的华山剑派就在此处。东边有所小小的庙宇，那就是玉女祠了。北面稀
稀落落有十几间房子，是华山派的地方，闲杂游客最好别往那里去。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"west"      : __DIR__"yunuci",
		"north"     : __DIR__"square",
		"westdown"  : __DIR__"zhenyue",
		"southdown" : __DIR__"yunupath1",
		"northeast" : __DIR__"xiaolu1",
	]));
	set("objects", ([
		__DIR__"npc/yue-lingshan" : 1,
	]));

	set("outdoors", "huashan" );
	set("coor/x", -860);
	set("coor/y", 190);
	set("coor/z", 120);
	setup();
}
 