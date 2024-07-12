//
// Created by olcay on 2019-05-16.
//

#include "TurkishAutoArgument.h"

/**
 * Sets the language.
 */
TurkishAutoArgument::TurkishAutoArgument() : AutoArgument(ViewLayerType::TURKISH_WORD){
}

/**
 * Checks all ancestors of the current parse node, until an ancestor has a tag of given name, or the ancestor is
 * null. Returns the ancestor with the given tag, or null.
 * @param parseNode Parse node to start checking ancestors.
 * @param name Tag to check.
 * @return The ancestor of the given parse node with the given tag, if such ancestor does not exist, returns null.
 */
bool TurkishAutoArgument::checkAncestors(ParseNode* parseNode, const string &name) {
    while (parseNode != nullptr){
        if (parseNode->getData().getName() == name){
            return true;
        }
        parseNode = parseNode->getParent();
    }
    return false;
}

/**
 * Checks all ancestors of the current parse node, until an ancestor has a tag with the given, or the ancestor is
 * null. Returns the ancestor with the tag having the given suffix, or null.
 * @param parseNode Parse node to start checking ancestors.
 * @param suffix Suffix of the tag to check.
 * @return The ancestor of the given parse node with the tag having the given suffix, if such ancestor does not
 * exist, returns null.
 */
bool TurkishAutoArgument::checkAncestorsUntil(ParseNode* parseNode, const string &suffix) {
    while (parseNode != nullptr){
        if (parseNode->getData().getName().find("-" + suffix) != string::npos){
            return true;
        }
        parseNode = parseNode->getParent();
    }
    return false;
}

/**
 * The method tries to set the argument of the given parse node to the given argument type automatically. If the
 * argument type condition matches the parse node, it returns true, otherwise it returns false.
 * @param parseNode Parse node to check for semantic role.
 * @param argumentType Semantic role to check.
 * @return True, if the argument type condition matches the parse node, false otherwise.
 */
bool TurkishAutoArgument::autoDetectArgument(ParseNodeDrawable *parseNode, ArgumentType argumentType) {
    ParseNode* parent = parseNode->getParent();
    switch (argumentType){
        case ArgumentType::ARG0:
            if (checkAncestorsUntil(parent, "SBJ")){
                return true;
            }
            break;
        case ArgumentType::ARG1:
            if (checkAncestorsUntil(parent, "OBJ")){
                return true;
            }
            break;
        case ArgumentType::ARGMADV:
            if (checkAncestorsUntil(parent, "ADV")){
                return true;
            }
            break;
        case ArgumentType::ARGMTMP:
            if (checkAncestorsUntil(parent, "TMP")){
                return true;
            }
            break;
        case ArgumentType::ARGMMNR:
            if (checkAncestorsUntil(parent, "MNR")){
                return true;
            }
            break;
        case ArgumentType::ARGMLOC:
            if (checkAncestorsUntil(parent, "LOC")){
                return true;
            }
            break;
        case ArgumentType::ARGMDIR:
            if (checkAncestorsUntil(parent, "DIR")){
                return true;
            }
            break;
        case ArgumentType::ARGMDIS:
            if (checkAncestors(parent, "CC")){
                return true;
            }
            break;
        case ArgumentType::ARGMEXT:
            if (checkAncestorsUntil(parent, "EXT")){
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}
