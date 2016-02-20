//Edited by fandog, 02/15/2000
inherit ROOM;
void create()
{
	set("short", "钱庄");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。
它发行的银票信誉非常好，通行全国。
    在对面的墙上挂了块牌子(paizi)。
LONG );
	set("exits", ([
		"east" : __DIR__"hzjie1",
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
		__DIR__"npc/chen" : 1
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("coor/x", -1510);
	set("coor/y", -2100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}