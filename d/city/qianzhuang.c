// Room: /d/yangzhou/qianzhuang.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "彦明钱庄");
	set("long", @LONG
彦明钱庄是江南的老字号了，从邸家第一代「邸彦明」创下这家钱
庄后传到现在，已经有上百年的历史了。彦明钱庄印发的银票各家钱庄
都给兑换，天下通用，信誉极好。钱庄里简简单单，就一个柜台，几个
伙计和帐房先生坐在后面，不时有人在此存钱，换钱。边上挂着个牌子
(paizi)。
LONG );
	set("exits", ([
		"east" : __DIR__"shilijie5",
	]));
	set("item_desc", ([
		"paizi" : @TEXT
     本钱庄提供以下服务：
      存钱        deposit或者cun
      取钱        withdraw或者qu
      钱币兑换    convert或者duihuan
      查帐        check或者chazhang
TEXT
	]) );

	set("objects", ([
		__DIR__"npc/qian" : 1
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("coor/x", 0);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}