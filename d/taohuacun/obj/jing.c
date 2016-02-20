// jing.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"育儿经"NOR, ({"jing"}));
        set("unit", "张");
        set("long",HIG" 
┏━━━━━━━━━ 早生贵子 ━━━━━━━━━━┓
┃┌──────────────────────┐┃
┃│  bsave             ：保存档案。            │┃
┃│  bteach/bjiao      ：教孩子武功。          │┃
┃│  bexercise/bdazuo  ：让孩子打坐练内力。    │┃
┃│  bpractice/blian   ：让孩子练习武功。      │┃
┃│  blearn/bxue       ：让孩子向师父学习武功。│┃
┃│  bstudy/bdu        ：让孩子读书学武功技能。│┃
┃│  hp,score,skills   ：查看孩子状态。        │┃
┃│  do <act>          ：让你们的孩子干活去。  │┃
┃│      目前do支持下列命令：                  │┃
┃│  go   get     give   hit     fight kill    │┃
┃│  wear remove  wield  unwield eat   drink   │┃
┃│  jifa enable  jiali  enforce yun   exert   │┃
┃│  bei  prepare fangqi abandon bai apprentice│┃
┃│                                            │┃
┃│                          侠客行一百恭贺    │┃
┃└──────────────────────┘┃
┗━━━━━━━━━━━━━━━━━━━━━━━━┛
"NOR);
        set("value", 0);
        set_weight(10);
        setup();
}


