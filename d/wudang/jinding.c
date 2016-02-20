//Room: jinding.c 金顶
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","金顶");
	set("long",@LONG
你感到寒意阵阵袭来，原来你已到了武当山的主峰天柱峰的绝顶。
前面的金殿由铜铸成，镀以黄金，每当旭日临空，整个殿宇金光闪闪，
故名金顶。天柱峰高高独立于群峰之上，东西壁立二山，名叫蜡烛峰，
中壁立一山似香炉，名香炉峰，万山千壑，隐隐下伏。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west"      : __DIR__"shierliantai",
		"south"     : __DIR__"zijincheng",
		"northdown" : __DIR__"santiangate",
	]));
	set("objects",([ /* sizeof() == 1 */
	    CLASS_D("wudang")+"/chongxu" : 1,
	]));
	set("outdoors", "wudang");
	set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -1040);
	set("coor/z", 180);
	setup();
	replace_program(ROOM);
}
