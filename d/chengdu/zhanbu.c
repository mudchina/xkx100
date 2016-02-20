// Room: /d/chengdu/zhanpu.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "占卜铺");
	set("long", @LONG
门口挂着一块招牌(sign)，里面显得有些空空荡荡的，瞎眼先生坐
在一张黑漆的方桌后，桌上铺者一张白布，上面摆着一筒算命用的竹签
和几枚铜钱。方桌前有一张供客人坐的凳子。
LONG	);
	set("exits", ([
		"south" : __DIR__"xijie1",
	]));
	set("item_desc",([
		 "sign": "人算不如天算，天算不如我算。\n",
	]));
	set("no_clean_up", 0);
       	set("coor/x", -8070);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

