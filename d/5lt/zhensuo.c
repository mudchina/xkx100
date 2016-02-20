// Room: /d/5lt/zhensuo.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "青蛙诊所");
	set  ("long",  @LONG
这里便是江湖医生青蛙的诊所了。柔和的灯光下，陶瓷地板清洁明
亮，搭配着墙角的几丛文竹、龟背和君子兰，入门就给人宁静的感觉。
弥散着淡淡香气的房间里有几扇玻璃门，里屋隐隐传来护士们的阵阵谈
笑声。门口摆放一张桌子，一个相貌清秀的年轻人正襟危坐翻看着厚厚
的书籍，一杯铁观音微微冒着热气。墙上没有一般诊所里常见的锦旗奖
状，只有门口一张广告(guanggao）说明了此处的所用。
LONG);
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
三黄宝蜡丸：\t一两黄金
三清换质丹：\t一两黄金
黑石玉洞丹：\t十两黄金\n"
	]));
	set("exits",  ([  //sizeof()  ==  2
		"west"  :  __DIR__"sroad2",
		"up"    :  __DIR__"zhensuo2",
	]));
	set("objects",  ([
		__DIR__"npc/afrog": 1,
		__DIR__"npc/huoji": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -140);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
}
