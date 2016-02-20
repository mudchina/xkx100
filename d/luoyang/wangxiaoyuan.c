//  Room:  /d/luoyang/wangxiaoyuan.c

inherit  ROOM;

void  create  ()
{
	set("short",  "小庭院");
	set("long",  @LONG
穿过挂着“幽径天姿成独秀，古园国色冠群芳”的角门，便是一个
十分秀巧的小园。园中小小的池塘中，浅浅的水里，养着一些细细的游
鱼，也养护着池塘边盛放的牡丹。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"   :  __DIR__"wangdayuan",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/obj/yaohuang" : random(2)+1,
		__DIR__"npc/obj/weizi" : random(2)+1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -610);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}