// Room: /yangzhou/pingshantang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","平山堂");
	set("long",@LONG
平山堂为欧阳修任扬州知州时建，堂北檐有贵州巡抚林肇元题“远
山来与此堂平”匾额，阐明堂名。堂中悬方颐书“平山堂”匾，东侧题
书“坐花载月”匾，取意于欧阳修遣人持荷行酒载月故事。西侧为“风
流宛在”匾。两侧悬挂朱公纯(lian)与汪国祯(lian1) 联。卷廊上悬“
放开眼界”匾，两侧悬挂嘉庆扬州知府伊秉绶联(lian2)。
    平山堂两廊壁间有东坡石刻(ke)，前庭植有琼花一株，紫藤两株，
欧公柳、春梅、蜡梅、紫薇各一株，以期四季花香。堂后庭院古柏遮天，
东西沿墙砖砌方形花台，栽植岁寒二友——天竹、腊梅，象征着欧苏情
谊。
LONG );
	set("item_desc", ([
		"lian" : HIC"
        晓起凭栏，六代青山都到眼
        晚来对酒，二分明月正当头
\n"NOR,
		"lian1" : HIC"
        山色湖光归一览
        欧公坡老峙千秋
\n"NOR,
		"lian2" : "
        过江诸山到此堂下
        太守之宴与众宾欢
\n",
		"ke" : "
宋元丰二年苏东坡三至扬州，忆及欧阳修的感慨之作《西江月·平山堂》

三过平山堂下，半生弹指声中，十年不见老仙翁，上龙蛇飞动。
欲吊文章太守，仍歌杨柳春风，莫言万事转头空，未转头时皆梦。
\n",
	]));
	set("objects", ([
		"/d/huashan/npc/youke" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"yongdao",
		"north" : __DIR__"gulintang",
	]));
	set("coor/x", -40);
	set("coor/y", 160);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}