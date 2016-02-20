// Room: /d/petroom.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "宠物铺");
	set("long", @LONG
这时一间宠物铺。高高的柜台后坐着一个老头。老头的身后是一排
排的笼子，五花八门的养了不少东东，柜台上摆着的牌子 (paizi)列出
了宠物种类，你想要就购买(goumai)一只吧。老头还兼卖各种宠物的饲
料宠物，随便买都成。宠物玩腻了不想玩，想换个种，也可以把旧的宠
物返还(return)给老头，然后再买一只新的。
LONG );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : HIR"
                                 扬州宠物店"HIC"

   ┏━"HIM"宠物"HIC"━"HIM"名称"HIC"━━━━"HIM"价目"HIC"━━━━┳━"HIM"宠物"HIC"━"HIM"名称"HIC"━━━━"HIM"价目"HIC"━━━━┓"HIC"
   ┃  "HIG"龙   dragon     "HIY"九十九两黄金"HIC"  ┃  "HIG"凤凰 phenix     "HIY"九十九两黄金"HIC"  ┃
   ┃  "HIG"麒麟 kylin      "HIY"九十九两黄金"HIC"  ┃  "HIG"象   elephant   "HIY"四十九两黄金"HIC"  ┃
   ┃  "HIG"狮   lion       "HIY"四十九两黄金"HIC"  ┃  "HIG"虎   tiger      "HIY"四十九两黄金"HIC"  ┃
   ┃  "HIG"豹   panther    "HIY"四十九两黄金"HIC"  ┃  "HIG"雕   vulture    "HIY"四十九两黄金"HIC"  ┃
   ┃  "HIG"熊   bear       "HIY"三十九两黄金"HIC"  ┃  "HIG"狐   fox        "HIY"三十九两黄金"HIC"  ┃
   ┃  "HIG"狼   wolf       "HIY"三十九两黄金"HIC"  ┃  "HIG"狗   dog        "HIY"三十九两黄金"HIC"  ┃
   ┃  "HIG"猪   pig        "HIY"三十九两黄金"HIC"  ┃  "HIG"鳄   crocodile  "HIY"三十九两黄金"HIC"  ┃
   ┃  "HIG"马   horse      "HIY"三十九两黄金"HIC"  ┃  "HIG"驴   donkey     "HIY"二十九两黄金"HIC"  ┃
   ┃  "HIG"牛   cattle     "HIY"二十九两黄金"HIC"  ┃  "HIG"猴   monkey     "HIY"二十九两黄金"HIC"  ┃
   ┃  "HIG"鹰   eagle      "HIY"二十九两黄金"HIC"  ┃  "HIG"鹿   deer       "HIY"二十九两黄金"HIC"  ┃
   ┃  "HIG"蛇   snake      "HIY"十九两黄金"HIC"    ┃  "HIG"貂   marten     "HIY"十九两黄金"HIC"    ┃
   ┃  "HIG"猫   cat        "HIY"九两黄金"HIC"      ┃  "HIG"鼠   mouse      "HIY"九两黄金"HIC"      ┃
   ┃  "HIG"兔   rabbit     "HIY"九两黄金"HIC"      ┃  "HIG"龟   tortise    "HIY"九两黄金"HIC"      ┃
   ┃  "HIG"鸡   chicken    "HIY"九两黄金"HIC"      ┃  "HIG"鸭   duck       "HIY"九两黄金"HIC"      ┃
   ┗━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━┛"HIB"
        goumai：购买    return：返还    zancun：暂存    lingqu：领取
\n"NOR,
	]));
	set("exits", ([
		"northeast" : __DIR__"caohebeijie",
	]));
	set("objects", ([
		__DIR__"npc/oldman" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
