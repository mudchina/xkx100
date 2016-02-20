//  Room:  /d/lanzhou/yangrouguan.c

inherit  ROOM;

void  create  ()
{
	set("short",  "羊肉馆");
	set("long",  @LONG
这是兰州城内最大的羊肉馆，卖的全是从城外草原上拉来的刚宰杀
的活羊，又鲜又嫩。南来北往的客商，到此地打尖，无不到这儿来尝尝
鲜。更有不少附近寺院的喇嘛到这儿偷腥。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  : __DIR__"market",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/xiaoer" : 1,
	]));
	set("coor/x", -9270);
	set("coor/y", 2690);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}