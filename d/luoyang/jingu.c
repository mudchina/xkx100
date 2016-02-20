// Room: /d/luoyang/jingu.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "金谷春晴");
	set("long",  @LONG
这里就是当年金谷洞内的金谷园。是西晋巨富石崇的别墅。他因与
贵族大地主王恺争富，修筑了金谷别墅，即称“金谷园”。阳春三月，
风和日暖的时候，桃花灼灼、柳丝袅袅，楼阁亭树交辉掩映，蝴蝶翩跃
飞舞于花间；小鸟啁啾，对语枝头。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"tongtuo",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
