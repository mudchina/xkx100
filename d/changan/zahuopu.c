// /d/changan/dangpu.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "南北行");
	set  ("long",  @LONG
这是一家气派不小的杂货铺，门楼高挂一个牌匾，上书红底金色三
个大字----“南北行”。掌柜懒洋洋地坐柜台后，几个伙计忙里忙外。
柜台上立着一块招牌(zhaopai)。
LONG);
	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"southroad1",
	]));
	set("objects",  ([  //sizeof()  ==  4
		__DIR__"npc/zhanggui" : 1,
	]));
	set("coor/x", -5030);
	set("coor/y", 980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
