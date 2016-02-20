// Room: /d/quanzhou/neitang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "内堂");
	set("long", @LONG
这里是药铺的内堂，东首摆了一个书架，上面放了不少医书。此外
还有几张桌椅(chair)。看来大概是药铺接待客人的地方。
LONG );
	set("item_desc", ([
		"chair"   : 
"一张椅子，抹拭得很干净，椅背刻着双龙抢珠的图案，两条龙刻得甚是
生动，张牙舞爪地抢夺一个镶在椅背上青光发亮的铁球(Iron Ball)。\n",
	]));
	set("exits", ([
		"out"   : __DIR__"jishitang",
	]));
	set("coor/x", 1830);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
