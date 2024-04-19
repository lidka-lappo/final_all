# from mendeleev import element

# def print_isotope_counts():
#     # Iterate through elements from Hydrogen to Einsteinium
#     for symbol in range(1, 100):
#         try:
#             elem = element(symbol)
#             isotopes = elem.isotopes
#             if isotopes:
#                 num_isotopes = len(isotopes)
#                 print(f" {num_isotopes}")
#             else:
#                 print(f"{elem.symbol}: No known isotopes.")
#         except ValueError:
#             # Skip if the element doesn't exist
#             pass

# if __name__ == "__main__":
#     print_isotope_counts()

from mendeleev import element

def find_isobar_counts():
    isobar_counts = {}
    # Iterate through elements from Hydrogen to Einsteinium
    for symbol in range(1, 99):
        try:
            elem = element(symbol)
            isotopes = elem.isotopes
            if isotopes:
                for isotope in isotopes:
                    mass_number = isotope.mass_number
                    if mass_number not in isobar_counts:
                        isobar_counts[mass_number] = 1
                    else:
                        isobar_counts[mass_number] += 1
        except ValueError:
            # Skip if the element doesn't exist
            pass
    
    # Print the number of isobars for each mass number
    for mass_number, count in isobar_counts.items():
        print(f"{mass_number} : {count}")

if __name__ == "__main__":
    find_isobar_counts()


# from mendeleev import element

# def find_isobar_counts():
#     isoton_counts = {}
#     # Iterate through elements from Hydrogen to Einsteinium
#     for symbol in range(1, 100):
#         try:
#             elem = element(symbol)
#             isotopes = elem.isotopes
#             if isotopes:
#                 for isotope in isotopes:
#                     n_number = isotope.mass_number - elem.atomic_number;
#                     if n_number not in isoton_counts:
#                         isoton_counts[n_number] = 1
#                     else:
#                         isoton_counts[n_number] += 1
#         except ValueError:
#             # Skip if the element doesn't exist
#             pass
    
#     # Print the number of isobars for each mass number
#     for n_number, count in isoton_counts.items():
#         print(f" {n_number}:{count}")

# if __name__ == "__main__":
#     find_isobar_counts()